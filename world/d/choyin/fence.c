// Room: /d/choyin/fence.c
# include <room.h>
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
ŵ���һƬ���֣��������ѣ���������ͷ����Ŀ�Ĺˣ�û��·��
��΢��է��������ֳ�һ������(fence)......

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
                      "west" : __DIR__"club.c", 
                      "eastup" : __DIR__"rockyu.c",
]));
        set("item_desc", ([
                "fence":"��������ƶ��������죬û�������������ע�⵽����������
һ����ã�����������\n",
          ]) );
create_door("west", "����", "east", DOOR_CLOSED);
        set("no_clean_up", 0);      
	setup();
	replace_program(ROOM);
}
