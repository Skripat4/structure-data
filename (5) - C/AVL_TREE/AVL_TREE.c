struct node
{
 int parent;
 int item;
 int left,right;
 char b; //balance for avl tree
}

struct node m[100]; //memory for avl - tree
int headTree; //number index of the head avl-tree
int f; //free index

void addAvlNode(int *head, int item)
{
int i=*head;
int j=0;
while(i!=0){
j=i;
if (m[i].item<item){ i=m[i].right;} else {i=m[i].left;}
}//while i!=0

if (j==0) {*head=f;}
else
if(m[j].item<item){m[j].right=f;} else {m[j].left=f;}

m[f].item=item;
m[f].parent=j;
m[f].left=0;
m[f].right=0;
m[f].b=0;
i=f;
f++;

//correct balance
int q=1;
while (j!=0 && q==1){
 if(m[j].right==i) {m[j].b=m[j].b+1;} else {m[j].b-1;}
 if(m[j].b==0){q=0;}
 if(abs(m[j].b)==2){q=2;} else {i=j;j=m[j].parent;}
}//while j!=0 && q==1


//balanced
if(q==0){}
else
{
if(m[j].b==2 && m[i].b==1){
	mm=m[j].parent;
	n=m[i].left;
	m[n].parent=j;
	if(mm==0){*head=i;}else{if(m[mm].left==j){m[mm].left=i;}else{m[mm].right=i;}}
	m[i].parent=mm;
	m[j].parent=i;
	m[j].right=n;
	m[i].left=j;
	m[i].b=0;
	m[j].b=0;
	}

if(m[j].b==-2 && m[i].b==-1){
	mm=m[j].parent;
	n=m[i].right; //!
	m[n].parent=j;
	if(mm==0){*head=i;}else{if(m[mm].left==j){m[mm].left=i;}else{m[mm].right=i;}}
 	m[i].parent=mm;
	m[j].parent=i;
	m[j].right=j;//!
	m[i].left=n;//!
	m[i].b=0;
	m[j].b=0;
}

if(m[j].b==2 && m[i].b==-1){
	mm=m[j].parent;
	n=m[m[i].left].left;
	q=m[m[i].left].right;
	if(mm==0){*head=m[i].left;}else{if(m[mm].left==j){m[mm].left=m[i].left;}else{m[mm].right=m[i].left;}}
 	m[m[i].left].parent=mm;
	mm=m[i].left;
	m[j].parent=mm;
        m[i].parent=mm;
	m[mm].right=i;
	m[mm].left=j;
	m[i].left=q;
	m[j].right=n;
	m[n].parent=j;
 	m[q].parent=i;
	m[mm].b=0;
	m[i].b=0;
	m[j].b=0;
}

if(m[j].b==-2 && m[i].b==1){
	mm=m[j].parent;
	n=m[m[i].right].left;
	q=m[m[i].right].right;
	if(mm==0){*head=m[i].right;}else{if(m[mm].left==j){m[mm].left=m[i].right;}else{m[mm].right=m[i].right;}}
 	m[m[i].right].parent=mm;
	mm=m[i].right;
	m[j].parent=mm;
        m[i].parent=mm;
	m[mm].right=j;
	m[mm].left=i;
	m[j].left=n;
	m[i].right=q;
	m[n].parent=j;
 	m[q].parent=i;
	m[mm].b=0;
	m[i].b=0;
	m[j].b=0;
}

}//if balanced

}