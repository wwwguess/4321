inherit NPC;

string ask_me();
void create()
{
	set_name("����", ({ "ben yin","yin"}) );
	set("gender", "����" );
	set("title", "����������");
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
	set("inquiry" ,([
	"������" : (:ask_me():),
	"��������" : "��ʩ�������Ǵ�ʲô����ɣ���\n",
	"������" :  "��ʩ������������ҽ��������ɣ���\n",
	]));

	setup();
//	carry_object("/d/baituo/obj/jiasha")->wear();
}

string ask_me()
{
	object me=this_player();
	if(me->query_temp("marks/ask_temp0"))
		{
		me->set_temp("marks/ask_temp1",1);
		return "�����Ǳ��µ�����֮����������ǰ������ʧ��ʩ�������һش��\n         ���ı�����л����\n";
		}
	else
		return "��ʩ���������ԡ���\n";
}

int accept_object(object who, object ob)
{
        if (  (string)ob->query("name") == "����")		{
		message_vision("�����ϲ��������лʩ����ʩ��������Ե�ˣ��뵽Ĳ����ȡ����֮����\n", who);
		who->set_temp("marks/find_temp",1);
		who->move("/d/tianlongsi/banruotai");
		return 1;
		}
	return 0;
}
