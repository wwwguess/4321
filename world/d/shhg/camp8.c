// ROOM:__DIR__"camp8"

inherit ROOM;
void create()
{
        set("short","����Ӫ��");
	set("long",@LONG                                   
��ͷ����Ӫ������Ƥ�������ϣ������ޱȣ������������죬˫������
ͼ����ǰ����Ȼ������֮�ƣ������������������������ǡ�����������ȫ
��һ�ࡢһ�ġ�һ�ϡ�һ�ѡ�һ������ī�±������ԣ��������ϣ���ı��
�ң��ɲ���������η��
LONG
	); // eof(long)
	
	set("exits",([ /* sizeof()==1*/
        	"west" : __DIR__"camp7",
	]) ); //eof(exits)

	set("objects",([
		__DIR__"npc/general" : 1,
		__DIR__"npc/adviser" : 1,
	]) );
	
	setup();
	
//	replace_program(ROOM);
} //EOF
