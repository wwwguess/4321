
#include <room.h>
inherit ROOM;

void create()
{
     set("short", "����");
	set("long", @LONG
����ר��ׯ�ڼ���ķ��ã���һ������¥���ݶ����������ߣ���
����⸲���̽�ͭ�ߡ����ڹ���  ���顸��ڤ��������������������
���񡸷�ˡ����������������ձڣ���̬�����������ó�������񣬡�
�����࣬��һ��̴�����Ϣ��
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
     "east" :__DIR__"upcenter",

]));

    set("objects", ([
        __DIR__"npc/statue" : 1,
    ]) );
    create_door("east","̴��ľ��","west", DOOR_CLOSED);
	setup();
	replace_program(ROOM);
}
