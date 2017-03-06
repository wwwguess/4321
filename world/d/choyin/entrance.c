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
		"west" :	"/d/choyin/bridge5",
		"east" :	__DIR__"taolin",
]));

        set("objects", ([
                CLASS_D("scholar") + "/master":1,
                CLASS_D("scholar") + "/othello" : 1,
        ]) );
        set("valid_startroom", 1);

        setup();

}

int valid_leave(object me,string dir)
{
        if ( dir=="east" && !(string)me->query("marks/����") )
		return notify_fail("���еĵ�·�������۵�ס��.\n");
	if (dir=="east")
        	me->set("taolin_steps", 3);
	return ::valid_leave(me,dir);
}

