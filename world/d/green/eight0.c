#include <room.h>

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
��������������ȥ��ֻ��һƬ�������Ұ��Ȼ���������ƺ�
����һ�����ܵı���������Զ���ľ�ɫģ�������������
�Լ����һ��Ʈ�������ڡ���һ����������һ��·��(sign)��
�����
LONG
);
	set("exits", ([ /* sizeof() == 4 */
	  "south" : __DIR__"entrance",
	  "north" : __DIR__"closed"  ,
	  "west"  : __DIR__"eight0"  ,
	  "east"  : __DIR__"eight1"  ,
	]));

	set("item_desc",([/* sizeof() == 1 */
	"sign" : "·����д�ţ�  ��--"
		 "��Ϊ�أ������������������������"
		 "���׻�����������ȸ���档\n"
	])
	);
	
	set("outdoors","green");
	set("no_clean_up",0);
	setup();
	replace_program(ROOM);
}


