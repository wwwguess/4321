#include <room.h>

inherit ROOM;

void create()
{
   set("short", "��������");
	set("long", @LONG
ͨ���� ������ ����������Ժ��������Ϊ��Ů֮���ޣ�����Ů
�˾��С����Ų��������Ų�������������Ƕ��ſ���Ϊ��Ů����
����ԺΪׯ��Ů�����᷿������԰������һ��С�ţ�Ϊׯ�ڸ�����
ԡ��С���ء������Ͻ����˺��Ҵ��롣
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
     "north" :__DIR__"corridor7",
     "south" :__DIR__"flowerc",
     "east" :__DIR__"bathroom1",

]));
     create_door("north","������","south", DOOR_CLOSED);
     create_door("east","С����","west", DOOR_CLOSED);

	setup();
	replace_program(ROOM);
}
