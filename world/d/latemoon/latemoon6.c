#include <room.h>

inherit ROOM;

void create()
{
    set("short","���շ�");
	set("long", @LONG
�������涼�ǵ�����ǽ��(wall)��ͨ��ׯ�ڵ��ӷ������
�����������ʡ˼����
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
      "east" :__DIR__"latemoon5",
]));

        set("item_desc", ([
                "wall": @TEXT
    ����ϸ�ۿ�ʯǽ��ͻȻ����ԭ��������ǽ������ԼԼ������
һ������ãã���������޵ľ����ݷ��ǻþ�����������ʵ����
����Ŀ���һ�״ʣ�������������˵����������������󡣡�
TEXT
        ]) );

      set("objects", ([
         __DIR__"npc/funlin" : 1 ]) );
     create_door("east","ͭ��","west", DOOR_CLOSED);
	setup();
	replace_program(ROOM);
}
