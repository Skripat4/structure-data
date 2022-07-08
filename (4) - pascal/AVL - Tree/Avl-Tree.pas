TYPE
 node = record
    parent 	: integer;
    item 	: integer;
    left,right 	: integer;
    b 		: shortInt; //balance for avl tree
  end;

VAR  
m : array [0..100] of node; 	// memory for avl - tree
headTree : integer; 		// number index of the head avl-tree
f : integer; 			// freeIndex

PROCEDURE addAvlNode(var head:integer;item:integer);
var
 i,j,mm,n,q:integer;
begin
  i := head;
  j := 0;
  while i<>0 do
   begin
     j := i;
     if m[i].item < item then i:=m[i].right else i:=m[i].left;
   end; //while i<>0

   if j = 0 then head:=f else
   if m[j].item < item then m[j].right := f else m[j].left := f;
   m[f].item := item;
   m[f].parent := j;
   m[f].left := 0;
   m[f].right := 0;
   m[f].b := 0;
   i := f;
   inc(f);

   //correct balance
   q:=1;
   while (j<>0) and (q=1) do
    begin
      if m[j].right = i then m[j].b:=m[j].b+1 else m[j].b := m[j].b-1;
      if m[j].b = 0 then q := 0;
      if abs(m[j].b) = 2 then q := 2 else begin
                                        i := j;
                                        j := m[j].parent;
                                      end;
    end;//while

   //balanced
   if q = 0 then begin end
   else
    begin
      if (m[j].b = 2) and (m[i].b = 1) then begin
                                          mm := m[j].parent;
                                          n := m[i].left;
                                          m[n].parent := j;
                                          if mm = 0 then head := i
                                          else
                                           begin
                                             if m[mm].left = j then m[mm].left := i
                                                              else m[mm].right := i;
                                           end; //else if
                                          m[i].parent := mm;
                                          m[j].parent := i;
                                          m[j].right := n;
                                          m[i].left := j;
                                          m[i].b := 0;
                                          m[j].b := 0;
                                        end;
                                   
      if (m[j].b = -2) and (m[i].b = -1) then begin
                                          mm := m[j].parent;
                                          n := m[i].right;  {!}
                                          m[n].parent := j;
                                          if mm = 0 then head := i
                                          else
                                           begin
                                             if m[mm].left = j then m[mm].left := i
                                                              else m[mm].right := i;
                                           end; //else if
                                          m[i].parent := mm;
                                          m[j].parent := i;
                                          m[j].left := n; {!}
                                          m[i].right := j; {!}
                                          m[i].b := 0;
                                          m[j].b := 0;
                                        end;
    if (m[j].b = 2) and (m[i].b = -1) then begin
                                         mm := m[j].parent;
                                         n := m[m[i].left].left;
                                         q := m[m[i].left].right;
                                         if mm=0 then head:=m[i].left
                                          else
                                           begin
                                             if m[mm].left=j then m[mm].left:=m[i].left
                                                              else m[mm].right:=m[i].left;
                                           end; //else if
                                           m[m[i].left].parent:=mm;
                                           mm:=m[i].left;
                                           m[j].parent:=mm;
                                           m[i].parent:=mm;
                                           m[mm].left:=j;
                                           m[mm].right:=i;
                                           m[j].right:=n;
                                           m[i].left:=q;
                                           m[n].parent:=j;
                                           m[q].parent:=i;
                                           m[mm].b:=0;
                                           m[i].b:=0;
                                           m[j].b:=0;
                                       end;
       if (m[j].b=-2) and (m[i].b=1) then begin
                                         mm:=m[j].parent;
                                         n:=m[m[i].right].left;
                                         q:=m[m[i].right].right;
                                         if mm=0 then head:=m[i].right
                                          else
                                           begin
                                             if m[mm].left=j then m[mm].left:=m[i].right
                                                              else m[mm].right:=m[i].right;
                                           end; //else if
                                           m[m[i].right].parent:=mm;
                                           mm:=m[i].right;
                                           m[j].parent:=mm;
                                           m[i].parent:=mm;
                                           m[mm].right:=j;
                                           m[mm].left:=i;
                                           m[j].left:=n;
                                           m[i].right:=q;
                                           m[n].parent:=j;
                                           m[q].parent:=i;
                                           m[mm].b:=0;
                                           m[i].b:=0;
                                           m[j].b:=0;
                                       end;
    end;//else q=0
end;