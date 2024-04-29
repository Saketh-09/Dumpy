import numpy as np
from Utils.TimeSeriesUtil import euclidean_dist
ts_length = 96

class PqItemSeries:
    def __init__(self, t, q, free, ndc):
        self.need_deep_copy = ndc
        self.need_free = free
        self.ts = t
        self.dist = euclidean_dist(self.ts, q)

    def copy_data(self):
        if not self.need_deep_copy:
            return
        assert self.ts is not None
        tmp = np.copy(self.ts)
        self.ts = tmp
        self.need_free = True
        self.need_deep_copy = False
