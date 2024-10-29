#Not fully correct, "([)]" case fails
class Solution:
    def isValid(self, s: str) -> bool:
        l = ["}","]",")"]
        r = ["{","[","("]

        #s = "{}[](){{}[}]"

        t = ""
        for u in s:
        
            for x,y in zip(l,r):
                
                if x == u:
                    if y in t:
                        v = t.index(y)
                        #print(t,'before removal')
                        #t = t.replace(t[v],'')
                        t = t[:v] + t[v+1:]
                        #print(t,'after removal')
                    else:
                        return False
                if y == u:
                    t = t + y
                    #print(t)
                    continue
        if '' == t:
            return True
                    
