#include <room.h>

inherit ROOM;

void create()
{
	set("short", "��ɳ�Ǵ���");
	set("long", @LONG
ͨ������ʿ����һ���̲飬�㱻������ڡ�����������������������������
һ�ɷ��ٵľ����������϶����ſ���Ц�ݡ������������Ĵ����
����ȥ����ϡ���Կ����������Ĵ��š�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : "/d/yulan/gate3",
  "east" : "/d/yulan/gate1",
]));

       create_door("east", "��ɳ�Ǵ���", "west", DOOR_CLOSED);

        set("no_clean_up", 0);
       	set("outdoors", "maintown");

	setup();
	replace_program(ROOM);
}
