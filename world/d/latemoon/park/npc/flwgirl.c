// flowergirl.c

inherit NPC;

void create()
{
	set_name("�ɻ���Ů", ({ "girl" }) );
	set("gender", "Ů��" );
	set("age", 15);
	set("per", 30-random(15) );
        	set("long", 
		"�ɻ���Ů�����������С������С�͵�����ׯ��ժ�𻨣���ֹ\n"
		"Ƽ��ϲ�����ǣ�Ҳ�̸�������Щ�������书��ʱ����ˣ���Щ��\n"
		"Ů�Ĺ��򻹶�����\n"
	);
	set("combat_exp", 20000);
	set("attitude", "friendly");
         	set("chat_chance", 4);
       	set("chat_msg", ({
"��Ƥ�Ĳɻ���Ů������������  *^G^* \n",
"�ɻ���Ů˵��������ɽ�Ĺ���������ׯ����ˣ���֪����\n",
"�ɻ���Ů������ߵ���ϼ��˫������������˵�����Һ���ȥ�Ƕ�������\n",
"�ɻ���Ů�ֹ��ţ���˵�Ƕ��Ĺ��кü����ء�\n",
       }) );

        	set("chat_chance_combat", 10);
        	set("chat_msg_combat", ({
"�ɻ���Ů��ü΢����˵�������۸������С����\n",
"�ɻ���Ů˵������Ҫ��������ȡ�֣��û�õ�嶾���㣡\n",
"�ɻ���Ů������������������������ң�\n",
        	}) );
	set("inquiry", ([
		"����ɽ" : "�Ǿ��ǺӺ���ѧ�������ɽ��ɽ�ϵĹ����ܶ�ģ���֪����\n",
	]) );

	set_skill("parry", 30);
	set_skill("dodge", 70);
	set_skill("unarmed", 120);
	set_skill("throwing", 150);
       	set_skill("stormdance", 45);

        map_skill("dodge", "stormdance");
        set_skill("force", 15);
        set("force", 500);
        set("max_force", 500);
        set("force_factor", 0);

	setup();
        	carry_object("/u/cloud/obj/npc/girl/pink_cloth")->wear();
        	for(int i=1; i<=2; i++){
	carry_object("/d/latemoon/park/npc/obj/guihua")->wield();
        	}
}


