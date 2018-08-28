
#Converted to ue4 use from: https://www.tensorflow.org/get_started/mnist/beginners
#mnist_softmax.py: https://github.com/tensorflow/tensorflow/blob/r1.1/tensorflow/examples/tutorials/mnist/mnist_softmax.py

# Import data
from tensorflow.examples.tutorials.mnist import input_data

import tensorflow as tf
import unreal_engine as ue
from TFPluginAPI import TFPluginAPI

import operator

class MnistSimple(TFPluginAPI):
	
	#expected api: storedModel and session, json inputs
	def onJsonInput(self, jsonInput):
	
		return jsonInput

	#expected api: no params forwarded for training? TBC
	def onBeginTraining(self):
		ue.log("starting mnist simple training")
		# Simple hello world using TensorFlow

		# Create a Constant op
		# The op is added as a node to the default graph.
		#
		# The value returned by the constructor represents the output
		# of the Constant op.
		hello = tf.constant('Hello, TensorFlow!')

		# Start tf session
		sess = tf.Session()

		# Run the op
		print(sess.run(hello))
		ue.print_string("tensorflow script")
		ue.print_string(sess.run(hello))
		
		return ''

#required function to get our api
def getApi():
	#return CLASSNAME.getInstance()
	return MnistSimple.getInstance()
