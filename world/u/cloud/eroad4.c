// Room: /u/cloud/eroad4.c

inherit ROOM;

void create()
{
        set("short", "�賡");
        set("long", @LONG
�����������Ĳ賡�����ʢ����Ҷ����������в��ٲ蹤��æ��
�ɲ衣
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "northwest" : "/u/cloud/eroad3",
]));

        set("objects", ([
                "/u/cloud/npc/worker" : 6,
        ]) );

        set("outdoors", "cloud");

        setup();
        replace_program(ROOM);
}

