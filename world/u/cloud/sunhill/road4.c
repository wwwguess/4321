// Room: /u/sunhill/road4.c

inherit ROOM;

void create()
{
        set("short", "��ɽС��");
        set("long", @LONG
��������᫵Ļ���С����
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "westdown" : __DIR__"road3",
  "southup" : "/d/sanyen/sroad2",
//"southup" : __DIR__"hillsmoke/entrance",
]));
        set("outdoors", "cloud");

        setup();
        replace_program(ROOM);
}

