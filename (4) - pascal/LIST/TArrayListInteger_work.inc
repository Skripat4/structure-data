
constructor TArrayListInteger.create(sizeList:integer);
VAR I:integer;
BEGIN
 size:=sizeList+1;
 setLength(list,size);
 for i:=1 to size -2  do
  list[i].next:=i+1;
 list[0].next:=0;
 list[size-1].next:=0; 
 free:=1;
END;
PROCEDURE TArrayListInteger.createList(var head,tail:integer;x:integer);
BEGIN
 HEAD:=free;
 TAIL:=HEAD;
 free:=list[free].next;
 list[TAIL].next:=0;
 list[HEAD].value:=x;
END;
PROCEDURE TArrayListInteger.DeleteList(var head,tail:integer);
BEGIN
 list[tail].next:=free;
 free:=head;
 head:=0;
 tail:=0;
END;
PROCEDURE TArrayListInteger.AddToTail(var tail:integer;x:integer);
BEGIN
 list[tail].next:=free;
 tail:=free;
 free:=list[free].next;
 list[tail].next:=0;
 list[tail].value:=x;
END;

PROCEDURE TArrayLIstInteger.AddToHead(var head:integer;x:integer);
VAR temp:integer;
BEGIN
 temp:=list[free].next;
 list[free].next:=head;
 head:=free;
 free:=temp;
 list[head].value:=x;
END;

 PROCEDURE TArrayListInteger.AddAfter(index:integer;x:integer);
VAR
  temp:integer;
BEGIN
 temp:=list[free].next;
 list[free].next:=list[index].next;
 list[index].next:=free;
 list[free].value:=x;
 free:=temp;
END;

PROCEDURE TArrayListInteger.AddAfter(var tail:integer;index:integer;x:integer);
VAR
  temp:integer;
BEGIN
 temp:=list[free].next;
 list[free].next:=list[index].next;
 list[index].next:=free;
 list[free].value:=x;
 if index=tail then tail:=free;
 free:=temp;
END;

PROCEDURE TArrayLIstInteger.deleteAfter(var tail:integer;index:integer);
VAR 
 temp : integer;
BEGIN
 temp:=list[index].next;
 if temp=tail then tail:=index;
 list[index].next:=list[ list[index].next ].next;
 list[temp].next:=free;
 free:=temp;
END;
PROCEDURE TArrayListInteger.deleteHead(var head:integer);
var temp:integer;
BEGIN
 temp:=list[head].next;
 list[head].next:=free;
 free:=head;
 head:=temp;
END;