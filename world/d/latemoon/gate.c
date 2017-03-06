#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
	set("short", "����ׯ����");
	set("long", @LONG
�����������С���ľ�ͷ��һ�������������Ŵ�լ
Ժ�����������ǰ���ſڹ�����������(lantern),����д
�����֣�������һ������Ĵ�լԺ���������������Ұ��
��ʹ�������Щͻأ����լ���ϱߡ����߶���ï�ܵ�����
������Ҳû��������·��
LONG
	);
	set("item_desc", ([
		"lantern" : "�����ϼ���������ּ�д����\n"
			BRED HIW "��ϼ������Ӱ��ϡ \n��Ӱ�߹Һͷ���Լ \n" NOR
	]) );

	set("exits", ([
	//	"northeast" :	__DIR__"sroad4",
		"east"	:	"/u/cloud/latemoon/entrance",
		"enter" :		__DIR__"front_yard",
	]));
	
	create_door ("east", "����", "west", DOOR_CLOSED);
 
	set("outdoors", "latemoon");

	setup();
	replace_program(ROOM);
}
