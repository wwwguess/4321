          // houhuayuan1.c
inherit ROOM;
void create()
{
        set("short", "��԰");
        set("long", @LONG
�����ǻ�ɽ�ɵĺ�԰�������˻��ݡ�����Сͯ���ڽ���
�����ǿ����������˳��������͡�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"buwei1",
  "south" : __DIR__"fanting",
  "west":__DIR__"houhuayuan2",
  "east" : __DIR__"liangong",
]));
        set("objects", ([
                __DIR__"npc/xiaotong" : 2,
        ]));

        set("no_clean_up", 0);
        set("outdoors", "xx" );
        setup();
        replace_program(ROOM);
}
