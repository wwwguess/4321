#include <room.h>

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
��������������ȥ��ֻ������һ�̣���Ұǧ������Ŀ�������
�ǲ����ܵı������𣬽�����Զ���ľ�ɫģ���������������
�����һ��Ʈ�������ڡ���һ����������һ��·��(sign)
�������
LONG
);
	set("exits", ([ /* sizeof() == 4 */
	  "south" : __DIR__"stoneroom",
	  "north" : __DIR__"eight7"  ,
	  "west"  : __DIR__"eight6"  ,
	  "east"  : __DIR__"closed"  ,
	]));

	set("item_desc",([/* sizeof() == 1 */
	"sign" : "·����д�ţ�  Ǭ--"
		 "ǬΪ�죬�����������������������"
		 "���׻����棬����ȸ������\n"
	])
	);
	
	set("outdoors","green");
	set("no_clean_up",0);
	setup();
}

int valid_leave(object me,string dir)
{
	if ( dir == "south" )
		me->set("������",1);
	return ::valid_leave(me,dir);
}

