from manim import *
from pathlib import Path

import os
import numpy as np


class Visualize(Scene):
    def construct(self):
        square = Square()
        circle = Circle()
        self.play(Create(square))
        self.play(Transform(square, circle))
        self.play(FadeOut(square))

    @staticmethod
    def fetch_positions(path: str):
        path = Path(path)
        if (not (os.path.exists(path) and path.suffix==".npy")):
            return None
        positions = np.load(path)
        return positions