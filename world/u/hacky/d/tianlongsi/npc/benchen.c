inherit NPC;

void create()
{
	set_name("����", ({ "ben chen","chen"}) );
	set("gender", "����" );
	set("class", "bonze");
	set("age", 70);
	set("shen_type", 1);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);

	set("kee", 3500);
	set("max_kee", 3500);
	set("gin", 1500);
	set("max_gin", 1500);
	set("force", 3000);
	set("max_force", 3000);
	set("jiali", 150);
	set("combat_exp", 800000);
	set("score", 1000000);

	set_skill("force", 120);
	set_skill("hunyuan-yiqi", 120);
	set_skill("dodge", 180);
	set_skill("shaolin-shenfa", 180);
	set_skill("parry", 120);
	set_skill("finger", 185);
	set_skill("staff", 120);
	set_skill("liumai-shenjian", 180);
	set_skill("weituo-gun", 120);
	set_skill("buddhism", 120);
	set_skill("literate", 120);

	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("parry", "liumai-shenjian");
	map_skill("finger", "liumai-shenjian");
	map_skill("staff", "weituo-gun");
	prepare_skill("finger","liumai-shenjian");	
	
//	set("inquiry" ,([
//	"������" : "�ܼҾ���ض����㣬˵������͵������\n",
//	]));

	setup();
//	carry_object("/d/baituo/obj/jiasha")->wear();
}

