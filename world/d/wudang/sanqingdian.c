// sanqingdian.c �����
// by Xiang

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
	���������������������䵱�ɻ�͵ĵص㡣����Ԫʼ����̫�ϵ�
���������Ͼ��������㰸���������ơ���ǽ���ż���̫ʦ�Σ����Ϸ��ż�����
�š��������������ȣ��ϱ�������Ĺ㳡�������Ǻ�Ժ��
LONG
	);
	set("valid_startroom", 1);
	set("exits", ([
		"south" : __DIR__"guangchang",
		"north" : __DIR__"houyuan",
		"east" : __DIR__"donglang1",
		"west" : __DIR__"xilang",
	]));
	set("objects", ([
		CLASS_D("wudang") + "/guxu" : 1,
		CLASS_D("wudang") + "/song" : 1]));
	setup();
	replace_program(ROOM);
	call_other("/obj/board/wudang_b","???");
//	"/clone/board/wudang_b"->foo();
}
/*
void init()
{
	object me;
	mapping skill_status;
	string *sname;
	int i, level; 
	float exper;

	me = this_player();

	exper = to_float(me->query("combat_exp"));

	if ( !(skill_status = me->query_skills()) ) return;
	sname  = keys(skill_status);

	for(i=0; i<sizeof(skill_status); i++) 
	{
		level = skill_status[sname[i]];
		if( pow(to_float(level), 3.0) / 10.0 > exper 
		&& exper > 100.0
		&& sname[i] != "buddhism"
		&& sname[i] != "literate"
		&& sname[i] != "taoism" ) 
		{
			level = ceil( pow( exper*10.0, 0.333333) );
			me->set_skill(sname[i], level);
		}
	}
}
*/
