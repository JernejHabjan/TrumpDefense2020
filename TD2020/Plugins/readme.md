2018-09-01-18-54
I Downloaded these plugins from
	https://github.com/getnamo/tensorflow-ue4
as a binary release
	tensorflow-ue4.20-v0.9.0-cpu
	
then run following commands when in editor and tensorflow is installed in background
import upypip as pip
pip.install('pandas')
pip.install('pygame')
pip.install('pydot')
pip.install('graphviz')


remember to call "clear_session()" from keras lib before running your PitWrapper() or LearnWrapper() on async function like onBeginPlay, othewise you will get exception in load_checkpoint