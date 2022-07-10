
 ItemListInteger = record
  value:integer;
  next:integer;
end;

 TarrayListInteger = class
 protected
  list:array of ItemListInteger;
  size:integer;
  free:integer;
 public
  constructor create(sizeList:integer);
  procedure createList(var head,tail:integer;x:integer);
  procedure DeleteList(var head,tail:integer);
  procedure AddToTail(var tail:integer;x:integer);
  procedure AddToHead(var head:integer;x:integer);  
  procedure AddAfter(index:integer;x:integer);overload;
   procedure AddAfter(var tail:integer;index:integer;x:integer);overload;

  procedure deleteAfter(var tail:integer;index:integer);
  procedure deleteHead(var head:integer);
 end;