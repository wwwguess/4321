#include <room.h>

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
��������������ȥ��ֻ�������죬�����ѵ��������ƺ�����һ��
���ܵı���������Զ���ľ�ɫģ��������������Լ����һ��
Ʈ�������ڡ���һ����������һ��·��(sign)�������
LONG
);
	set("exits", ([ /* sizeof() == 4 */
	  "south" : __DIR__"eight5",
	  "north" : __DIR__"eight4"  ,
	  "west"  : __DIR__"eight6"  ,
	  "east"  : __DIR__"closed"  ,
	]));

	set("item_desc",([/* sizeof() == 1 */
	"sign" : "·����д�ţ�  ��--"
		 "��Ϊ����������������������棬"
		 "���׻�����������ȸ������\n"
	])
	);
	
	set("outdoors","green");
	set("no_clean_up",0);
	setup();
	replace_program(ROOM);
}


