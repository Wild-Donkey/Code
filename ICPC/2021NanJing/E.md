
$$
Val, His, Sum, Time, Len\\
Tag = {D, DHis, DSqHis}
$$

Edit with Tag_.

His += Val(Time_ - Time) + Tag_.DHis * Sum * 2 + Tag_.DSqHis * Len

Tag.DSqHis += Tag.D^2(Time_ - Tag.Time) + Tag.D * Tag_.DHis * 2 + Tag_.DSqHis

Tag.DHis += Tag_.D(Time_ - Tag.Time) + Tag_.DHis

Val += 2 * Sum(Tag_.D) + Tag_.D^2 * Len

Sum += Tag_.D * Len

Tag.D += Tag_.D

Time = Time_