/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package ai.socket;

import ai.core.AI;
import ai.core.AIWithComputationBudget;
import ai.core.ParameterSpecification;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.io.StringReader;
import java.net.Socket;
import java.util.ArrayList;
import java.util.List;
import org.jdom.Element;
import org.jdom.input.SAXBuilder;
import rts.GameState;
import rts.PlayerAction;
import rts.units.UnitTypeTable;
import util.XMLWriter;

/**
 *
 * @author santi
 */
public class SocketAI extends AIWithComputationBudget {
    public static int DEBUG = 0;
    
    public static final int LANGUAGE_XML = 1;
    public static final int LANGUAGE_JSON = 2;
    
    UnitTypeTable utt = null;
            
    int communication_language = LANGUAGE_XML;
    String serverAddress = "127.0.0.1";
    int serverPort = 9898;
    Socket socket = null;
    BufferedReader in_pipe = null;
    PrintWriter out_pipe = null;
    
    public SocketAI(UnitTypeTable a_utt) {
        super(100,-1);
        utt = a_utt;
        try {
            connectToServer();
        }catch(Exception e) {
            e.printStackTrace();
        }
    }
    
        
    public SocketAI(int mt, int mi, String a_sa, int a_port, int a_language, UnitTypeTable a_utt) {
        super(mt, mi);
        serverAddress = a_sa;
        serverPort = a_port;
        communication_language = a_language;
        utt = a_utt;
        try {
            connectToServer();
        }catch(Exception e) {
            e.printStackTrace();
        }
    }
    
    
    public void connectToServer() throws Exception {
        // Make connection and initialize streams
        socket = new Socket(serverAddress, serverPort);
        in_pipe = new BufferedReader(new InputStreamReader(socket.getInputStream()));
        out_pipe = new PrintWriter(socket.getOutputStream(), true);

        // Consume the initial welcoming messages from the server
        while(in_pipe.ready()) in_pipe.readLine();

        reset();
    }
    
    
    @Override
    public void reset() {
        try {
            // set the game parameters:
            out_pipe.append("budget " + TIME_BUDGET + " " + ITERATIONS_BUDGET + "\n");
            out_pipe.flush();
            
            // wait for ack:
            in_pipe.readLine();

            // send the utt:
            while(in_pipe.ready()) in_pipe.readLine();
            out_pipe.append("utt\n");
            if (communication_language == LANGUAGE_XML) {
                XMLWriter w = new XMLWriter(out_pipe, " ");
                utt.toxml(w);
                w.flush();
                out_pipe.append("\n");
                out_pipe.flush();                
            } else if (communication_language == LANGUAGE_JSON) {
                utt.toJSON(out_pipe);
                out_pipe.append("\n");
                out_pipe.flush();
            } else {
                throw new Exception("Communication language " + communication_language + " not supported!");
            }
            
            // wait for ack:
            in_pipe.readLine();
            
            // read any extra left-over lines
            while(in_pipe.ready()) in_pipe.readLine();
        }catch(Exception e) {
            e.printStackTrace();
        }
    }
    

    @Override
    public PlayerAction getAction(int player, GameState gs) throws Exception {
        // send the game state:
        out_pipe.append("getAction " + player + "\n");
        if (communication_language == LANGUAGE_XML) {
            XMLWriter w = new XMLWriter(out_pipe, " ");
            gs.toxml(w);
            w.flush();
            out_pipe.append("\n");
            out_pipe.flush();

            // wait to get an action:
            //while(!in_pipe.ready());
                
            // parse the action:
            String actionString = in_pipe.readLine();
            if (DEBUG>=1) System.out.println("action received from server: " + actionString);
            Element action_e = new SAXBuilder().build(new StringReader(actionString)).getRootElement();
            PlayerAction pa = PlayerAction.fromXML(action_e, gs, utt);
            pa.fillWithNones(gs, player, 10);
            return pa;
        } else if (communication_language == LANGUAGE_JSON) {
            gs.toJSON(out_pipe);
            out_pipe.append("\n");
            out_pipe.flush();
            
            // wait to get an action:
            //while(!in_pipe.ready());
                
            // parse the action:
            String actionString = in_pipe.readLine();
            // System.out.println("action received from server: " + actionString);
            PlayerAction pa = PlayerAction.fromJSON(actionString, gs, utt);
            pa.fillWithNones(gs, player, 10);
            return pa;
        } else {
            throw new Exception("Communication language " + communication_language + " not supported!");
        }        
    }
    

    @Override
    public void preGameAnalysis(GameState gs, long milliseconds) throws Exception 
    {
        // send the game state:
        out_pipe.append("preGameAnalysis " + milliseconds + "\n");
        if (communication_language == LANGUAGE_XML) {
            XMLWriter w = new XMLWriter(out_pipe, " ");
            gs.toxml(w);
            w.flush();
            out_pipe.append("\n");
            out_pipe.flush();
                
            // wait for ack:
            in_pipe.readLine();
        } else if (communication_language == LANGUAGE_JSON) {
            gs.toJSON(out_pipe);
            out_pipe.append("\n");
            out_pipe.flush();
            
            // wait for ack:
            in_pipe.readLine();
        } else {
            throw new Exception("Communication language " + communication_language + " not supported!");
        }        
    }

    
    @Override
    public AI clone() {
        return new SocketAI(TIME_BUDGET, ITERATIONS_BUDGET, serverAddress, serverPort, communication_language, utt);
    }
    

    @Override
    public List<ParameterSpecification> getParameters() {
        List<ParameterSpecification> l = new ArrayList<>();
        
        l.add(new ParameterSpecification("Server Address", String.class, "127.0.0.1"));
        l.add(new ParameterSpecification("Server Port", Integer.class, 9898));
        l.add(new ParameterSpecification("Language", Integer.class, LANGUAGE_XML));
        
        return l;
    }
}
