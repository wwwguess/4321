#include <room.h>

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
��������������ȥ��ֻ��Ǧ�Ƶͳ�����Ȼһ�����磬����һ����ף�
ԶɽΪ֮���죬�����ƺ�����һ�����ܵı���������Զ���ľ�ɫ
ģ��������������Լ����һ��Ʈ�������ڡ���һ����������
һ��·��(sign)�������
LONG
);
	set("exits", ([ /* sizeof() == 4 */
	  "south" : __DIR__"closed",
	  "north" : __DIR__"eight5"  ,
	  "west"  : __DIR__"eight4"  ,
	  "east"  : __DIR__"eight3"  ,
	]));

	set("item_desc",([/* sizeof() == 1 */
	"sign" : "·����д�ţ�  ��--"
		 "��Ϊ�ף����������棬�����������"
		 "���׻�����������ȸ������\n"
	])
	);
	
	set("outdoors","green");
	set("no_clean_up",0);
	setup();
	replace_program(ROOM);
}


