inherit NPC;
 
void create()
{
	object ob;

    set_name("����÷", ({ "yu-may","yumay","may" }) );
	set("gender", "Ů��" );
	set("age",18);
	set("long", @TEXT
����÷������ׯ����ֹƼ����Ů������ׯ�����������ӣ����
����ׯ�Ӵ�����Ĺ���������������
TEXT
);
	set("per", 30);
	set("class", "dancer");
    set("combat_exp", 60000);

	set_skill("unarmed",60);
    set_skill("throwing", 90);
    set_skill("dodge", 70);
     set_skill("stormdance" , 30);
	set_skill("force",50);
     map_skill("dodge", "stormdance");

    set("force", 2000);
	set("max_force", 500);
	set("force_factor",2);

	set("chat_chance", 7);
	set("chat_msg", ({
        "����÷΢Ц��˵������������ׯ�ǡ� ������ѣ����񻻼� ��\n",
        "����÷����һ���ɻ�Ц��˵���ҽ�����һ�����������ء�����?\n",
		"����÷΢Ц��˵��������֧��������ò��ã�\n",
        "����÷΢Ц��˵�����ҵ������ò��ã���������뷼����������������Զม�\n"
	}) );
	set("inquiry", ([
		"��������" : "���������ء���һ�ֻ�Ӱʽ�貽���������λ�Ӱ��\n",
        "ѧ��" : "��!�ҽ���...���������ء�(dancing out)�� ..... \n" +
               "������÷ָ�����㽥������! \n",
		"��" : "�һ���������ڡ���Ӱʽ�貽����\n",
		"���" : "���Ǹ��ɰ���Ů���������е����ԣ���˵��̰�汻���� \n"+
                  "�����ҡ���˵������������Ŷ��\n",
		"������" : "ׯ�����˻����������ɲ�ͬ��Ʒ��\n",
        "�׺�����" : "��һ��ʧ���Ծõġ��������衹\n",
	]));
	create_family("����ׯ", 3, "�����");

	setup();
	ob = carry_object(__DIR__"obj/needle");
	ob->set_amount(30);
    ob->wield();
	carry_object(__DIR__"obj/deer_boot")->wear();
	carry_object(__DIR__"obj/skirt3")->wear();
}

void init()
{
	object ob;

	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}

}
void greeting(object ob)
{
    object teacup;
	if( !ob || environment(ob)!=environment() ) return;
	switch( random(2) ) {
		case 0:
			say( "��÷����΢Ц�����ƵĶ���˵��\n  ��λ" + 
				RANK_D->query_respect(ob)
				+ "����ã���ӭ��������ׯ��������\n");
			break;
		case 1:
            {
			say( "��÷����΢Ц����ϸ��˫�������裬\n ˵������λ" +
				RANK_D->query_respect(ob)
				+ "����ã���ӭ��������ׯ�����ò裡\n");
             if ( ob->query_temp("latemoon/��") ) 
                 command("smile");
                 else  {
                teacup = new("/d/latemoon/obj/teacup");
                teacup->move(ob);
                ob->set_temp("latemoon/��", 1);
                say ("�����ϵȽ�����!��Ʒ��һ�¡�\n");
                   }
            }
		}
}
