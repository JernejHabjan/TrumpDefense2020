from typing import List, Tuple, Dict
from numpy import array

StrPresentation = array(List[List[List[bytes]]])
StateEncoding = List[List[List[int]]]
ActionEncoding = List[List[List[List[int]]]]

# NodeType = Dict[Tuple[StateEncoding, StrPresentation], int]

Pi = List[int]
V = float
CoachEpisode = List[Tuple[ActionEncoding, Pi, V]]

CanonicalBoard = array(StateEncoding)


ValidMoves =  array(List[int])