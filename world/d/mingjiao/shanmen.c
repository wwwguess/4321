// damen.c
// by yuer

inherit ROOM;

void create()
{
	set("short", "ɽ��");
	set("long", @LONG
     ���������ܶ�ĵڶ����ؿ������Ƹ�Ϊ��Ҫ�����滷ɽ���м�
   ����С·��ͨ���������
LONG
	);
        set("outdoors", "mingjiao");

	set("exits", ([
		"southdown" : __DIR__"shanlu2",
		"northup" : __DIR__"guangchang",
	     
	]));
//      set("objects",([
//		CLASS_D("mingjiao") + "/yanyuan.c" : 1,
//            ]));

	setup();
}

/* int valid_leave(object me, string dir)
{
        mapping myfam;
        myfam = (mapping)me->query("family");
        if ((!myfam || myfam["family_name"] != "����") && dir == "northup" &&
                objectp(present("yan yuan", environment(me))))
           return notify_fail("��ԫ�ȵ����㲻�����̽�ͽ���������ڡ�\n");
        return ::valid_leave(me, dir);
} */

