//ROOM:/d/suzhou/yuanlin5.c
//by dwolf
//97.11.7 
         
#include <ansi.h>
inherit ROOM;            

string* objects = ({
	"xiao",
	"teacup",
	"chahu",
});

void create()
{                           
	int i = random(sizeof(objects));
	set("short", RED"����԰��"NOR);
	set("long", @LONG
        	��һ����Сͤ�ڣ�ֻ�������˱ǣ���Щ������٣�Խ��Խ�Դ䣬��
����ʵ����ɺ������һ�㣬�����ɰ���ͤ��ѩ��һ�㣬�������ʣ�ʯ����һ������ƿ��
�й�����֦�ջ����Ա߷���һֻ�һ�ײ�걲豭���ѣ��ƺ�����������Ϣ�����ֶ�
�衣Զ�����͵��䣬û���˳�·��
LONG
	);                                        
	set("exits", ([
		"east" : __DIR__"yuanlin3",  
]));             
	set("objects", ([
		__DIR__"npc/obj/"+objects[i] : 1]));
	setup();
}
  

