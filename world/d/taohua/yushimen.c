// Room: /d/new_taohua/yushimen.c

inherit ROOM;

void create()
{
	set("short", "���Ҵ���");
	set("long", @LONG
���������Ҵ��ţ������������ң�������Ů���ҡ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */  
  "north" : __DIR__"nanqinshi",
  "south": __DIR__"nvqinshi",
  "west" : __DIR__"houting",
]));
	

	setup();

}
int valid_leave(object me, string dir)
{

        if (me->query("gender")=="����" && dir=="south")
              return notify_fail("�е��Ӳ�����Ů���ҡ�\n");
        if (me->query("gender")=="Ů��" && dir=="north")
              return notify_fail("Ů���ӵ������Ҹ�ʲô?\n");
        
          return ::valid_leave(me, dir);
}
