#include <room.h>

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
��������������ȥ��ֻ�����滷ˮ��ֻ�н���һ��½�أ�ˮ����
�ƺ�����һ�����ܵı���������Զ���ľ�ɫģ�������������
�Լ����һ��Ʈ�������ڡ���һ����������һ��·��(sign)��
�����
LONG
);
	set("exits", ([ /* sizeof() == 4 */
	  "south" : __DIR__"eight2",
	  "north" : __DIR__"eight1"  ,
	  "west"  : __DIR__"eight3"  ,
	  "east"  : __DIR__"closed"  ,
	]));

	set("item_desc",([/* sizeof() == 1 */
	"sign" : "·����д�ţ�  ��--"
		 "��Ϊˮ����������������������棬"
		 "���׻�����������ȸ������\n"
	])
	);
	
	set("outdoors","green");
	set("no_clean_up",0);
	setup();
	replace_program(ROOM);
}


