#!/usr/bin/env python3
def control(channel,on): return {"can_id":"0x300","data":[channel,1 if on else 0]}
def threshold(channel,current_a):
    v=int(current_a*100); return {"can_id":"0x301","data":[channel,(v>>8)&255,v&255]}
if __name__=="__main__":
    print("CONTROL",control(0,True))
    print("THRESHOLD",threshold(0,5.0))