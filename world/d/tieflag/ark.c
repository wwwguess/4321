#include <room.h>  
inherit ROOM;
void create()
{
	set("short","����");
	set("long",@LONG
��ɴ�й��߻����������뵣�һλ������ϥ��������֮�ϡ����ű���һ��¯����
�ƴ���¯��ȽȽ���𣬳������������䡣
LONG
);
	set("exits/out" ,__DIR__"outboat");
	set("objects",([
		__DIR__"npc/jiayi" : 1,
    ]) );

    setup();
}
                  