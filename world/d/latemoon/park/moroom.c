inherit ROOM;

void create()
{
   set("short", "����С��");
	set("long", @LONG
��һ����С���ڣ�ֻ�������˱ǣ���Щ������٣�Խ��Խ�Դ䣬
������ʵ����ɺ������һ�㣬�۴��ɰ�������ѩ��һ�㣬��������  
������һ������ƿ���й�����֦�ջ����Ա߷��������顢��걲豭  
���ѣ�����ֻ������ɴ��ᣱ��죬Ҳʮ����ʵ��
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
       "east" :__DIR__"moon3",

]));

    set("objects", ([
        __DIR__"npc/girl_yu" : 1,
        __DIR__"npc/dodo1" : 1,
    ]) );
	setup();
	replace_program(ROOM);
}
