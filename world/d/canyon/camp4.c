// ROOM:__DIR__"camp4"

inherit ROOM;
void create()
{
        set("short","С��Ӫ��");
	set("long",@LONG                                   
�����һ��Ⱥ��С������֪��������ʲô��Ӫ��������һ�����ӣ���
������˸�ʽ�����Ķľߣ�С��ʣ��Ͳ�ˮ��
LONG
	); // eof(long)
	
	set("exits",([ /* sizeof()==1 */
        	"north" : __DIR__"camp1",
	]) ); //eof(exits)

	set("objects",([
		__DIR__"npc/guard1" : 2,
		__DIR__"npc/guard2" : 1,
	]) );
	
	setup();
	
	replace_program(ROOM);
} //EOF
