#include <room.h>

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
��������������ȥ��ֻ�����������溮���ǣ����뱱���綴������
�ƺ�����һ�����ܵı����紵��ɢ��������Զ���ľ�ɫģ����������
�����Լ����һ��Ʈ�������ڡ���һ����������һ��·��(sign)��
�����
LONG
);
	set("exits", ([ /* sizeof() == 4 */
	  "south" : __DIR__"eight3",
	  "north" : __DIR__"closed"  ,
	  "west"  : __DIR__"eight2"  ,
	  "east"  : __DIR__"eight4"  ,
	]));

	set("item_desc",([/* sizeof() == 1 */
	"sign" : "·����д�ţ�  ��--"
		 "��Ϊ�磬�����������������������"
		 "���׻����棬����ȸ������\n"
	])
	);
	
	set("outdoors","green");
	set("no_clean_up",0);
	setup();
	replace_program(ROOM);
}


