#include <room.h>

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
��������������ȥ��ֻ����һ�������֮�У�����ֻ���ĳ߼�����
һ��½�أ������ƺ�����һ�����ܵı���������Զ���ľ�ɫģ��������
������Լ����һ��Ʈ�������ڡ���һ����������һ��·��(sign)
�������
LONG
);
	set("exits", ([ /* sizeof() == 4 */
	  "south" : __DIR__"eight5",
	  "north" : __DIR__"eight7"  ,
	  "west"  : __DIR__"closed"  ,
	  "east"  : __DIR__"eight6"  ,
	]));

	set("item_desc",([/* sizeof() == 1 */
	"sign" : "·����д�ţ�  ��--"
		 "��Ϊ�������������������������"
		 "���׻�����������ȸ���档\n"
	])
	);
	
	set("outdoors","green");
	set("no_clean_up",0);
	setup();
	replace_program(ROOM);
}


