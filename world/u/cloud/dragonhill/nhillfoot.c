// Room: /u/cloud/dragonhill/nhillfoot.c

inherit ROOM;

void create()
{
        set("short", "�����ڱ���");
        set("long", @LONG
��������������·ͨ��ѩͤ�����������������ڡ�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "northwest" : __DIR__"nroad",
  "southup" : __DIR__"hummock",
]));
        set("outdoors", "dragonhill");

        setup();
        replace_program(ROOM);
}
