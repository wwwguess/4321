// Room: /daemon/class/scholar/entrance.c

inherit ROOM;

void create()
{
	set("short", "����̨");
	set("long", @LONG
����������ׯ���ߵ�����̨��Ҳ�������سǵ�����ī��ʱ���ۼ�̸
��ʫ�ĵĵط���̨��Լʮ�ɣ����������������سǵĴ������ţ��Ӵ���
���е�ƬƬ˯��������������ͨ�����ߵĹ㳡�����ߺ��ϱ߸�����ʮ��
����������������ص�ʿ�˽����ǵ���Ʒ��������ϣ���õ�������ʶ��
������һƬ�����֣�����ʱ�ʹ������ϵ��������ӳ��εΪ�����صĵ�
һʢ����
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"west" : "/d/choyin/bridge5",
	]));
	set("objects", ([
		__DIR__"master" : 1,
		__DIR__"othello" : 1,
	]) );
	set("valid_startroom", 1);

	setup();
	call_other( "/obj/board/scholar_b", "???" );

	replace_program(ROOM);
}
