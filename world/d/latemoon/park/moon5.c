inherit ROOM;

void create()
{
   set("short", "��԰");
	set("long", @LONG
����һƬ��԰��԰����ֲ����ʮ����֦꣬�ɲԾ���֦Ҷ  
ïʢ��������������������������չ��������������̣������Ĺ�
��������Ѥ�������Ŵ󷽣��̺���������������޹����������
���������㡣
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
       "south" :__DIR__"moon3",
       "north" :__DIR__"moon2",

]));

    set("objects", ([
        "/d/latemoon/park/npc/flwgirl" : 4 ]) );
	setup();
}
