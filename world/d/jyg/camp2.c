// ROOM:__DIR__"camp2"

inherit ROOM;
void create()
{
        set("short","Ӫ����");
	set("long",@LONG
����Ǽ����ر�Ӫ��Ӫ����������һ�����𣬻��е�����������ڱ߱�����һ��ˮ
��������ǹٱ���������ˮ�õģ��ϲ�Ϊ��ƫ����Ӫ�ʣ���������
��������Ӫ�ʣ�����Ϊ�ӳ���Ӫ�ʡ����û������ðȻ�����ǻᱻ����
LONG
	); // eof(long)
	
	set("resource/water",1);

	set("exits",([ /* sizeof()==4 */
        	"north" : __DIR__"camp5",
        	"south" : __DIR__"camp6",
        	"east" : __DIR__"camp7",
        	"west" : __DIR__"camp1",
	]) ); //eof(exits)

	
	setup();
	
	replace_program(ROOM);
} //EOF
