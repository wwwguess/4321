#include <room.h>

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
��������������ȥ��ֻ��Ⱥɽ���ƣ���֪�������������ƺ�
����һ�����ܵı���������Զ���ľ�ɫģ�������������
�Լ����һ��Ʈ�������ڡ���һ����������һ��·��(sign)��
�����
LONG
);
	set("exits", ([ /* sizeof() == 4 */
	  "south" : __DIR__"eight1",
	  "north" : __DIR__"eight2"  ,
	  "west"  : __DIR__"closed"  ,
	  "east"  : __DIR__"eight0"  ,
	]));

	set("item_desc",([/* sizeof() == 1 */
	"sign" : "·����д�ţ�  ��--"
		 "��Ϊɽ�����������棬�����������"
		 "���׻�����������ȸ������\n"
	])
	);
	
	set("outdoors","green");
	set("no_clean_up",0);
	setup();
	replace_program(ROOM);
}


