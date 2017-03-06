// walker.c
// Date: YZC 96/01/19
// Date: Cleansword 96/02/05

inherit NPC;

void create()
{
          set_name("����", ({"xing zhe", "xing","walker",}));
	set("title", "���ֵ�ɮ");
	set("long",
		"����һλ�����ķ������ߣ���˪���棬��ɫ�Ҵң��ƺ����ڰ�һ�����¡�\n"
	);

	set("gender", "����");
	set("attitude", "heroism");
	set("class", "bonze");

	set("chat_chance", 70);

	set("chat_msg", ({
		"����˵������˵������ɽɽ������һ���̺����Ͻ�ħ�󷨵Ľ�շ�ħȦ�����з�ҷ�����\n",
                "����˵�����׽��Ϊ����ƪ������ƪ����ƪ��ȭ��ƪ�Ĳ�������ǰ�㶼��ɢʧ������\n",
                "����˵��������ȭ���ͺ�������������һ�����ƽ�������Ц����Ϸ�ҳ������˵ı��⡣\n",
                "����˵��������ʮ���޺����������ޱȣ�����������߿�˵�Ƿ�ë��ǣ�������һ���˲š�\n",
                "����˵�������µ������϶��£���������ʥɮ��ʮ���޺��������ߣ�����ʦ���ű���ȡ�\n",
                "����˵��������Ժ��������ʹ��ʦ��ȫ��������ɮ�����������Ǵ���Ҳ���ҿ�һ����\n",
                "����˵���������²ؾ�¥�ؾ�֮�������º��С��𷨾��䣬�书�ؼ�������˵������������\n",
                "����˵�������µ�����Ҫϰ������ɵ����������ͷ��߿���ȡ��е������黹��˾��\n",
                "����˵������������������ɮ��������¥�������޷𷨣��߲㴰��ƽ̨�ϸ����������\n",
                "����˵�������־�����ʮ����ר��һ�ţ����Ǵ��кô����������ڹ����գ���������ǿ��\n",
                "����˵�������µ������ܽϼ�սʤʦ�𱲣�����������ͬ�࣬��ʦѧϰ����������ա�\n",
		(: random_move :)
	}) );

	set("age", 35);
	set("shen_type", 1);
	set("str", 25);
	set("int", 20);
	set("con", 20);
	set("dex", 25);
	set("per", 15);
	set("max_kee", 500);
	set("max_gin", 100);
	set("force", 500);
	set("max_force", 500);
	set("force_factor", 30);
	set("combat_exp", 20000);
	set("score", 100);
	set("apply/attack",  30);
	set("apply/defense", 30);

	set_skill("force", 50);
	set_skill("blade", 50);
	set_skill("dodge", 50);
	set_skill("parry", 50);
	set_skill("shaolin-shenfa", 50);
	set_skill("cibei-dao", 50);
	set_skill("hunyuan-yiqi", 50);
        set_skill("finger", 50);
        set_skill("nianhua-zhi", 50);
	set_skill("strike", 50);
	set_skill("sanhua-zhang", 50);

        map_skill("finger", "nianhua-zhi");
        map_skill("strike", "sanhua-zhang");
	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("blade", "cibei-dao");
	map_skill("parry", "cibei-dao");

        prepare_skill("finger", "nianhua-zhi");
        prepare_skill("strike", "sanhua-zhang");


	setup();
	carry_object("/std/weapon/gangdao")->wield();
	carry_object("/d/shaolin/obj/cloth")->wear();
	add_money("silver", 50);
}

void init()
{
	object me, ob;
	mapping fam;

	::init();

	ob = this_player();
	me = this_object();
	
	if (interactive(ob) 
	&& !environment(ob)->query("no_fight")
        && ( (fam = ob->query("family")) && fam["family_name"] != "������" && ob->query("is_shaolin")) )
	{
		command("say ������޳�������ͽ���������ɣ�����\n");
		me->set_leader(ob);
		remove_call_out("kill_ob");
		call_out("kill_ob", 1, ob); 
	}       
}
