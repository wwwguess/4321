// Room: /u/cloud/dragonhill/shill.c

inherit ROOM;

void create()
{
        set("short", "����������");
        set("long", @LONG
���������ڵĶ����¡����ϵ�·ͨ�������������Ҫ�����ˡ�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "northup" : __DIR__"hummock",
  "southeast" : "u/cloud/entrance"
]));
        set("outdoors", "dragonhill");

        setup();
        replace_program(ROOM);
}
