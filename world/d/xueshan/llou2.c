//by dwolf
//llou2.c

#include <ansi.h>
inherit ROOM;
              
string* objects = ({
	"pipe", 
	"zhuxiao",
	"chabei",
});
	
void create()
{       
	int i = random(sizeof(objects));
	set("short", RED"�ر���"NOR);
	set("long", @LONG
	  ����ǰһ����һ���µ����������������ǰ�������Ӷ��Ǳ�������ϧ��
�˷�ֻ������һ���������һ���ص�����ͨ��ѩɽɽ�š�
LONG
	); 
	set("exits", ([
		"down" : __DIR__"foot.c",
	]));                            
	set("objects", ([
		__DIR__"npc/obj/"+ objects[i] : 1]));
	setup();
}
