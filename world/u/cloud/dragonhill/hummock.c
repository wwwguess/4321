// Room: /u/cloud/dragonhill/hummock.c

inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
����λ��ѩͤ�����������һ��ɽ������˵ɽ��ʱ����ǿ����·
���١�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "northdown" : __DIR__"nhillfoot",
  "southdown" : __DIR__"shillfoot",
]));

        set("objects", ([
                "/u/cloud/npc/gangster" : 2
]) );

        set("outdoors", "dragonhill");

        setup();
}
