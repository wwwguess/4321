#include <room.h>
inherit ROOM;

void create()
{
   set("short", "���᷿�ߵ�");
	set("long", @LONG
���������᷿�ߵ��ϡ��������ߵ��У�����ɵĳ��Ƽ��Ϲ���һ��
�����Ĺ���! �ߵ����԰���������滨��ݣ�����������һ�ֵ�������
������һ�������λ����ĳ������̻����ʻ��ͼ�Σ�����ʤ�ա�����
�㿴��һ���š�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
   "north" :__DIR__"wroad1",
   "east" :__DIR__"corridor7",
   "west" :__DIR__"westroom",
   "southup" : "/d/latemoon/upstar/upstar2",

]));

   create_door("west","��������","east", DOOR_CLOSED);
	setup();
	replace_program(ROOM);
}
