// laojun.c

inherit ROOM;

void create()
{
        set("short", "�Ͼ���");
	set("long", @LONG
��������Ҫ�������£�������������ЪϢ���Ͼ�����һ������೤��
ɽ�����ഫΪ̫���Ͼ������������Ͼ�����
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "westdown" : __DIR__"baichi",
  "northup" : __DIR__"bieyuan",
  "southup" : __DIR__"husun",
]));
        set("no_clean_up", 0);
        set("outdoors", "xx" );

        setup();
        replace_program(ROOM);
}
 
