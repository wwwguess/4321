
#include <room.h>
inherit ROOM;

void create()
{
    set("short","��Ժ�ߵ�");
	set("long", @LONG
������һ�������ϣ����Զ���̨ͥ���У�����������һ��
��������Ϣ������������ʯש�̳ɣ�һ�߽Ӻ�����Ժ��һ�ߵ�
��ͷ����һ����ʯ�ڻ�����������һͭ��(door)��
��һ���鷿��
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
    "west" :__DIR__"latemoon6",
    "south" :__DIR__"latemoonc",

]));

     create_door("west","ͭ��","east", DOOR_CLOSED);
	setup();
	replace_program(ROOM);
}
