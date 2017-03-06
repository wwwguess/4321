// Room: /d/shaolin/wuchang.c
// Date: YZC 96/01/19

inherit ROOM;




void create()
{
	set("short", "���䳡");
	set("long", @LONG
�����������µ����䳡����������޴�Ļ�����ʯ���̾͡�
��ǧ��Ĳ�̤��ʹ����Щʯ����ͬ���Ӱ�ƽ���⻬�����߽��ϻ�
��������ɳ�ӣ�ʮ����ɮ��������ϰ���ա������������һ����
����
LONG
	);

	set("exits", ([
		"south" : __DIR__"houdian",
		"east" : __DIR__"wuchang2",
		"west" : __DIR__"wuchang1",
		"north" : __DIR__"fzlou",
	]));

	set("outdoors", "shaolin");
	set("objects",([
		CLASS_D("shaolin") + "/dao-jue" : 1,
	]));
	setup();

}

/* ???????????
   CHANGED BY PAFF core dump!!! */
void no_init()
{
	object me;
	mapping skill_status;
	string *sname;
	int i, level; 
	float exper;

	me = this_player();

	exper = to_float(me->query("combat_exp"));
        printf("wuchagn:exper %f\n",exper);

	if ( !(skill_status = me->query_skills()) ) return;
	sname  = keys(skill_status);

	for(i=0; i<sizeof(skill_status); i++) 
	{
		level = skill_status[sname[i]];
                printf("wuchagn:%s(%d)\n",sname[i],level);
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



