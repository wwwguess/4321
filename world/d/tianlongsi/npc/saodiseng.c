inherit NPC;

string ask_me1();
string ask_me2();

void create()
{
	set_name("扫地僧", ({ "saodi seng","seng"}) );
	set("gender", "男性" );
	set("class", "bonze");
	set("age", 100);
	set("shen_type", 1);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);

	set("kee", 1000);
	set("max_kee", 1000);
	set("gin", 1000);
	set("max_gin", 1000);
	set("force", 3000);
	set("max_force", 3000);
	set("jiali", 20);
	set("combat_exp", 80000);
	set("score", 10000);

	set_skill("force", 100);
	set_skill("hunyuan-yiqi", 100);
	set_skill("dodge", 100);
	set_skill("shaolin-shenfa", 100);
	set_skill("parry", 100);
	set_skill("finger", 100);
	set_skill("staff", 100);
	set_skill("liumai-shenjian", 100);
	set_skill("weituo-gun", 100);
	set_skill("buddhism", 120);
	set_skill("literate", 120);

	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("parry", "liumai-shenjian");
	map_skill("finger", "liumai-shenjian");
	map_skill("staff", "weituo-gun");
	prepare_skill("finger","liumai-shenjian");	
	set("inquiry" ,([
	"舍利子" : (:ask_me1():),
	"丢失" : (:ask_me2():),
	]));

	setup();
//	carry_object("/d/baituo/obj/jiasha")->wear();
}

string ask_me1()
{
	object me=this_player();
	if(me->query_temp("marks/ask_temp1"))
		return "“那是本寺的镇寺之宝，当年不知为何丢失了。”\n";
	else
		return "“你胡说八道什么？”\n";
}

string ask_me2()
{
	object me=this_player();
	if(me->query_temp("marks/ask_temp1"))
		{
		me->set_temp("marks/ask_temp2",1);
		return "“那天晚上我只看见一个黑影从塔上飞下，往后寺跑了。\n";
		}
	else
		return "“你胡说八道什么？”\n";
}

