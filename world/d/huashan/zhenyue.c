// zhenyue.c

inherit ROOM;

void create()
{
        set("short", "������");
	set("long", @LONG
���������Ϊƽ̹���ϡ���ɽ���οͶ��ڴ�������Ϣ�ټ���ǰ�С���
���м����ª�����磬���Ƕ�����ճ��ߣ�����ͷ��ЪϢ�ڴˡ�
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
  "northup" : __DIR__"canglong",
  "eastup" : __DIR__"chaoyang",
  "southup" : __DIR__"yunu",
]));
        set("no_clean_up", 0);
        set("outdoors", "xx" );

        setup();
        replace_program(ROOM);
}
 
